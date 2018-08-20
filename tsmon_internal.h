#ifndef __SIMPLE_TS_MONITORING_INTERNAL_HEADER__
    #define __SIMPLE_TS_MONITORING_INTERNAL_HEADER__

// TO DO - Place Holder
#include "tsmon_events.h"
#include "mutex"

#define MAX_SUPPORTED_PARALLEL_TSMON        (5)

class CTsMonitoringInfo
{
protected:
    typedef enum tagTsMonStatus
    {
            TSMON_STATUS_IDLE
        ,   TSMON_STATUS_RUNNING
    } TSMON_CTXT_STATUS;


public:
    CTsMonitoringInfo()
    {
        Reset();
    }

public:
    static TS_MON_CTXT TSMON_GetInstance(void);
    static void TSMON_ReleaseInstance(TS_MON_CTXT pvInstance);

    bool TSMON_StartMonitoring(TS_MON_CTXT pvInstance);
    bool TSMON_StopMonitoring(TS_MON_CTXT pvInstance);

protected:
    TSMON_CTXT_STATUS TSMON_GetStatus(void);
    void TSMON_SetStatus(TSMON_CTXT_STATUS enNewStatus);

private:
    CTsMonitoringInfo(const CTsMonitoringInfo &) = delete;  // No copy constructor
    CTsMonitoringInfo & operator = (const CTsMonitoringInfo &) = delete;    // No assignment operator

private:
    void Reset(void)
    {
        m_status = TSMON_STATUS_IDLE;
    }

private:
    std::mutex          m_lock;
    TSMON_CTXT_STATUS   m_status;
};

#endif /* !__SIMPLE_TS_MONITORING_INTERNAL_HEADER__ */