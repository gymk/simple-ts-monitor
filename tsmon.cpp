// TO DO - Place Holder

#include "tsmon_internal.h"
#include "tsmon_events.h"
#include "tsmon.h"
#include "bufferpool.h"

static simple_buffer_manager::CFixedSizeBufferPool<CTsMonitoringInfo> gTsMonInstanceList;

CTsMonitoringInfo::TSMON_CTXT_STATUS CTsMonitoringInfo::TSMON_GetStatus(void)
{
    std::unique_lock<std::mutex> lc(m_lock);

    return m_status;    // TO DO - Is this right way to do or do we need to store to a local and return local???
}

void CTsMonitoringInfo::TSMON_SetStatus(TSMON_CTXT_STATUS enNewStatus)
{
    std::unique_lock<std::mutex> lc(m_lock);

    m_status = enNewStatus;
}


TS_MON_CTXT CTsMonitoringInfo::TSMON_GetInstance(void)
{
    CTsMonitoringInfo * ctxt = gTsMonInstanceList.GetBuffer();

    if(nullptr != ctxt)
    {
        ctxt->Reset();
    }
    
    return ctxt;
}

void CTsMonitoringInfo::TSMON_ReleaseInstance(TS_MON_CTXT pvInstance)
{
    CTsMonitoringInfo * ctxt = static_cast<CTsMonitoringInfo*>(pvInstance);
    gTsMonInstanceList.ReleaseBuffer(ctxt);
}

bool CTsMonitoringInfo::TSMON_StartMonitoring(TS_MON_CTXT pvInstance)
{
    return false;
}

bool CTsMonitoringInfo::TSMON_StopMonitoring(TS_MON_CTXT pvInstance)
{
    return false;
}
