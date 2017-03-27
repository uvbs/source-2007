//======= Copyright � 1996-2006, Valve Corporation, All rights reserved. ======
//
// Purpose: The plugin entry and exit points
//
//=============================================================================

// Maya Headers

#include <maya/MFnPlugin.h>
#include <maya/MGlobal.h>

// Valve Headers

#include "appframework/appframework.h"
#include "vstdlib/iprocessutils.h"
#include "tier2/tier2.h"
#include "tier2/tier2dm.h"
#include "tier3/tier3dm.h"

// Local Headers

#include "VsMayaMPxFactory.h"

// Static Variables

bool g_okToUnload( true );	// Whether or not this plug-in is unloadable or not


//-----------------------------------------------------------------------------
//
// Purpose: Valve entry point called before any Valve DLLs are loaded to determine
//			which Valve DLLs this plugin requires
// Input  :
// Output : A const pointer to an array of AppSystemInfo_t's which must exist
//			after this function returns, could do a reference counted smart
//			pointer perhaps
//
//-----------------------------------------------------------------------------
DLL_EXPORT const AppSystemInfo_t *VsMayaGetAppSystems( )
{
	static const AppSystemInfo_t appSystems[] = 
	{
		{ "vstdlib.dll",			PROCESS_UTILS_INTERFACE_VERSION },

		{ "", "" }	// Required to terminate the list
	};

	return appSystems;
}


//-----------------------------------------------------------------------------
//
// Purpose: Valve entry point called after the Valve DLLs are loaded
// Input  : CreateInterfaceFn factory
// Output : true is everything is good, false otherwise
//
//-----------------------------------------------------------------------------
DLL_EXPORT bool VsMayaConnect( CreateInterfaceFn factory )
{
	ConnectTier1Libraries( &factory, 1 );
	ConnectTier2Libraries( &factory, 1 );
	ConnectTier3Libraries( &factory, 1 );

	MathLib_Init( 2.2f, 2.2f, 0.0f, 2.0f, false, false, false, false );

	if ( !g_pFullFileSystem )
	{
		Warning( "vsVmfIO is missing a required interface!\n" );
		return false;
	}

	// Can't unload this plugin until the libraries have been disconnected
	g_okToUnload = false;

	return true;
}


//-----------------------------------------------------------------------------
//
// Purpose: Valve entry point called when the Valve libraries are being unloaded
// Input  :
// Output :
//
//-----------------------------------------------------------------------------
DLL_EXPORT void VsMayaDisconnect()
{
	DisconnectTier3Libraries();
	DisconnectTier2Libraries();
	DisconnectTier1Libraries();

	// Ok to unload this plugin as the libraries have been disconnected
	g_okToUnload = true;
}


//-----------------------------------------------------------------------------
//
// Purpose: Entry point that Maya calls when this plugin is loaded into Maya
// Input  : The Maya MObject representing the plugin
// Output : MStatus::kSuccess if everything went ok, MStatus::kFailure otherwise
//
//-----------------------------------------------------------------------------
EXPORT MStatus initializePlugin( MObject mObject )
{
	MStatus regVal;
	MStatus retVal;

	MFnPlugin pluginFn( mObject, "Valve", "1.0", "Any" );

	MStatus mStatus = CVsMayaMPxFactoryBase::RegisterEverything( pluginFn );

	MGlobal::executeCommand( "loadPlugin -qt vstSmdIO" );

	return mStatus;
}


//-----------------------------------------------------------------------------
//
// Purpose: Exit point that Maya calls when this plugin is unloaded from Maya
// Input  : The Maya MObject representing the plugin
// Output : MStatus::kSuccess if everything went ok, MStatus::kFailure otherwise
//
//-----------------------------------------------------------------------------

EXPORT MStatus uninitializePlugin( MObject mObject )
{
	if ( !g_okToUnload )
		return MS::kFailure;

	MFnPlugin pluginFn( mObject );

	return CVsMayaMPxFactoryBase::DeregisterEverything( pluginFn );
}
