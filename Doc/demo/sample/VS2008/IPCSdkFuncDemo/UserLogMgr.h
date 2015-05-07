#ifndef _USER_LOG_MGR_H_
#define _USER_LOG_MGR_H_

#include <string>


typedef struct tagLogItem{
    TCHAR reason[256] ;
    TCHAR cmd[48] ;
    TCHAR time[24] ;
    TCHAR state[16] ;
}LogItem,*LPLogItem ;

class IUserLogMgr
{
public:
    virtual INT size() = 0 ;

    virtual LPLogItem get_ptr() = 0 ;

    virtual VOID push( CONST TCHAR* cmd_,CONST TCHAR* state_,CONST TCHAR* reason_) = 0 ;

    virtual VOID tofile( CONST TCHAR* filepath_) = 0 ;

};

class CUserLogMgr
{

public:
    
    static const INT MAX_ITEM_COUNT = 8*1024*1024 ;

    CUserLogMgr()
    {
        _lpData = new BYTE[MAX_ITEM_COUNT] ;

        _plist = (LPLogItem)(_lpData) ;

        _ItemPos = 0 ;
    }
    virtual ~CUserLogMgr()
    {
        delete[] _lpData ;
        _lpData = NULL;
        _plist = NULL;
        _ItemPos = 0 ;

    }
    
    INT size()
    {
        return _ItemPos ;
    }

    LPLogItem get_ptr()
    {
        return (LPLogItem)(_lpData) ;
    }

    VOID push( CONST TCHAR* cmd_,CONST TCHAR* state_,CONST TCHAR* reason_)
    {
        if( _ItemPos >=MAX_ITEM_COUNT)
        {
            _ItemPos = 0 ;
        }

        time_t tt ;

        time(&tt) ;

        tm* lptm = localtime(&tt) ;
        
        _stprintf_s( get_time_ptr(_ItemPos) ,get_time_size(),TEXT("%04d-%02d-%02d %02d:%02d:%02d"),lptm->tm_year+1900,lptm->tm_mon,lptm->tm_mday,lptm->tm_hour,lptm->tm_min,lptm->tm_sec ) ;//_tasctime((tm*)(mbtime->GetBuffer()))
        
        strcpy_s( get_cmd_ptr(_ItemPos),get_cmd_size(),cmd_) ;
        
        strcpy_s( get_state_ptr(_ItemPos),get_state_size(),state_) ;
        
        strcpy_s( get_reason_ptr(_ItemPos),get_reason_size(),reason_) ;
        
        _ItemPos++ ;
    }

    VOID tofile( CONST TCHAR* filepath_)
    {
        FILE* hf = _tfopen(filepath_,TEXT("wb") ) ;
        
        LPLogItem lpdata = get_ptr() ;

        TCHAR * str = new TCHAR[1024] ;


        for( int i = 0 ;i< _ItemPos ;i++ )
        {
            _stprintf_s( (TCHAR*)str ,1024*sizeof(TCHAR),TEXT("%-30s | %-60s | %-10s | %-128s \n"),lpdata->time,lpdata->cmd,lpdata->state,lpdata->reason ) ;

            fwrite(str,1,sizeof(TCHAR)*239,hf) ;    
        }
        
        delete[] str ;

        fclose(hf) ;
        
    }
protected:
    TCHAR* get_time_ptr(INT _pos)
    {
        return &((_plist[_pos]).time[0]) ;
    }
    size_t get_time_size()
    {
        return sizeof(_plist[0].time) ;
    }

    TCHAR* get_cmd_ptr(INT _pos)
    {
        return &(_plist[_pos].cmd[0]) ;
    }
    size_t get_cmd_size()
    {
        return sizeof(_plist[0].cmd) ;
    }

    TCHAR* get_state_ptr(INT _pos)
    {
        return &(_plist[_pos].state[0]) ;
    }

    size_t get_state_size()
    {
        return sizeof(_plist[0].state) ;
    }

    TCHAR* get_reason_ptr(INT _pos)
    {
        return &(_plist[_pos].reason[0]) ;
    }
    
    size_t get_reason_size()
    {
        return sizeof(_plist[0].reason) ;
    }
private:
    BYTE*        _lpData ;
    LPLogItem    _plist ;
    INT            _ItemPos ;
    
};

#endif//_USER_LOG_MGR_H_