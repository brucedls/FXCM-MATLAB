#ifdef DECLDIR 
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif


typedef void (__stdcall * fnCallBackFunc)(char* value, double msgType);
__declspec(dllexport)  void Register_Callback(fnCallBackFunc func);


DECLDIR int  __stdcall login_fc(const char* username, const char* pass, const char* connection, const char* url);
DECLDIR bool  __stdcall getHistoryPrices(const char *sInstrument, const char *sTimeframe,  const char* dtFrom,  const char* dtTo, const char* fileName);
DECLDIR int  __stdcall logout_fc();
DECLDIR int  __stdcall createMarketOrder(const char *sAccountID, int iAmount, const char *sBuySell, const char *tif, const char *instrument, const char *ticketNum);
DECLDIR int __stdcall createEntryOrder(const char *sAccountID, int iAmount, const char *sBuySell, const char *tif, const char *instrument, const char* StopLimit, const double price);
DECLDIR int __stdcall createELSorder(const char *sAccount, int iAmount, const char *sBuySell, const char *instrument, const char *ordType1, const char *tif, const double price, const double limitPrice, const double stopPrice, const int trailStop);
DECLDIR int __stdcall getRealTimePrices(const char *instrument);
DECLDIR int __stdcall stopPrices(const char *instrument);

void __stdcall fc_mexCallback(char *msg, double msgType);
void printLog(std::string str);

#ifdef __cplusplus
}
#endif

