#pragma once
#include "EuroScopePlugIn.h"
#include "HttpHelper.hpp"
#include "CPDLCSettingsDialog.hpp"
#include "DataLinkDialog.hpp"
#include <string>
#include <algorithm>
#include "Constant.hpp"
#include "Mmsystem.h"
#include "SMRRadar.hpp"

#define MY_PLUGIN_NAME      "vSMR"
#define MY_PLUGIN_VERSION   "RC1-dev-e32"
#define MY_PLUGIN_DEVELOPER "Pierre Ferran"
#define MY_PLUGIN_COPYRIGHT "GPL v3"
#define MY_PLUGIN_VIEW_AVISO  "SMR radar display"

using namespace std;
using namespace EuroScopePlugIn;

class CSMRPlugin :
	public EuroScopePlugIn::CPlugIn
{
public:
	CSMRPlugin();
	virtual ~CSMRPlugin();

	//---OnCompileCommand------------------------------------------

	virtual bool OnCompileCommand(const char * sCommandLine);

	//---OnFunctionCall------------------------------------------

	virtual void OnFunctionCall(int FunctionId, const char * sItemString, POINT Pt, RECT Area);

	//---OnGetTagItem------------------------------------------

	virtual void OnGetTagItem(CFlightPlan FlightPlan, CRadarTarget RadarTarget, int ItemCode, int TagData, char sItemString[16], int * pColorCode, COLORREF * pRGB, double * pFontSize);

	//---OnControllerDisconnect------------------------------------------

	virtual void OnControllerDisconnect(CController Controller);

	//---OnTimer------------------------------------------

	virtual void OnTimer(int Counter);

	//---OnRadarScreenCreated------------------------------------------

	virtual CRadarScreen * OnRadarScreenCreated(const char * sDisplayName, bool NeedRadarContent, bool GeoReferenced, bool CanBeSaved, bool CanBeCreated);
};

