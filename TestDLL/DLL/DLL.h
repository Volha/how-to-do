// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

// This class is exported from the DLL.dll
class DLL_API CDLL {
public:
	CDLL(void);
	// TODO: add your methods here.
};

extern DLL_API int nDLL;
extern "C" DLL_API int fnDLL(void);
extern "C" DLL_API int Function(void);

