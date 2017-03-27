//*****************************************************************************
/*!
   \file xsi_command.h
   \brief Command and CommandArray class declarations.

   � Copyright 1998-2002 Avid Technology, Inc. and its licensors. All rights
   reserved. This file contains confidential and proprietary information of
   Avid Technology, Inc., and is subject to the terms of the SOFTIMAGE|XSI
   end user license agreement (or EULA).
*/
//*****************************************************************************

#if (_MSC_VER > 1000) || defined(SGI_COMPILER)
#pragma once
#endif

#ifndef __XSICOMMAND_H__
#define __XSICOMMAND_H__

#include <xsi_siobject.h>
#include <xsi_value.h>

namespace XSI {

class ArgumentArray ; // Forward declaration

//*****************************************************************************
/*! \class Command xsi_command.h
	\brief Represents an %XSI command (either built-in or custom).  This object encapsulates information on a command
	such as the name, category, arguments, where it is implemented etc.

	Custom commands behave just like built-in %XSI commands--they are logged in the history window and can be exposed
	to scripting.

	You can access all the built-in and custom commands installed in the system with Application::GetCommands.

	\note Make sure the name you use as a key to access a command in %XSI is the string returned by SIObject::GetName
	rather than Command::GetScriptingName. You can find the name of a command by running it and then checking the \a Edit
	menu (where the \b Name of the last executed command always appears after \c Repeat and \c Undo). You can find the
	\b ScriptingName of a command by running it and then checking the command log. You can also iterate over the entire
	collection of commands.

	Commands are primarily called from scripts, in which case they are invoked by calling the string returned by
	Command::GetScriptingName with the scripting syntax for calling a function. In effect they appear as if they are
	\a helper \a functions available to the script writer.  For example to call the custom command \c Foo from JScript
	the syntax is:

	\code 	Foo( arg1, arg2 ); \endcode

	The C++ API function Application::ExecuteCommand can be used to execute both built-in and custom commands.

	You can also place commands in toolbars and menus. There are two ways to place custom commands in %XSI menus.  The
	first is through the command category (see the ::siCommandCategory enum) and the second, more powerful approach, is
	through the Menu API.

	The arguments that a command accepts are encapsulated in its definition. All commands have a fixed number of arguments,
	and they are passed to the callback implementing the command in the order to be defined in the ArgumentArray. It is
	possible to define a default value and an ArgumentHandler for each argument, so commands are often invoked without
	specifying each argument value explicitly.

	%XSI supports three possible ways to define a custom command: the embedded command, the plug-in based command and the
	v1.5 command.  They are all based on the same Command object API but they have some subtle differences. The plug-in based
	command is the most convenient for commands implemented with the C++ API.  For information about the other approaches
	please see the \xl %Command object documentation in the \a Scripting \a Reference guide.

	The plug-in based approach, new with v4.0, involves implementing the definition and implementation of the custom command
	inside a self-installed plug-in (see PluginRegistrar::RegisterCommand).  Because multiple commands, Menu objects,
	CustomProperty objects and other elements can all be implemented inside the same \c .dll (or \c .so) module, it is often
	possible to write an entire sophisticated tool inside a single binary file.

	\note A command defined in this fashion is not persisted inside the \c .DSDynamicCommandMap file; instead its definition
	is regenerated by calling the \c Init callback each time the application is started. To edit the command definition, change
	the code inside the \c Init callback and reload the plug-in.  To remove the custom command, remove the plug-in script or dll.

	\note For more information please refer to the \a Custom \a Commands chapter (\xl cus_cmds in the \a SDK \a Customization guide).

	\since 4.0

	\eg This example is similar to the JScript example implemented in the Object %Model reference for the \xl %Command object.

	\code
		//*****************************************************************************
		//
		//	Example of Self-installed custom commands.
		//
		//	Note: For Windows there must also be a .def file as part of the .dsp
		//			and which contains the following contents:
		//
		//  EXPORTS
		//	XSILoadPlugin					@1 PRIVATE
		//	CommandHelloWorldCpp_Init		@2 PRIVATE
		//	CommandHelloWorldCpp_Execute 	@3 PRIVATE
		//	CommandSimpleCpp_Init			@4 PRIVATE
		//	CommandSimpleCpp_Execute 		@5 PRIVATE
		//	CommandSimpleObjectCpp_Init		@6 PRIVATE
		//	CommandSimpleObjectCpp_Execute 	@7 PRIVATE
		//
		//
		//*****************************************************************************

		#include <xsi_application.h>
		#include <xsi_argument.h>
		#include <xsi_command.h>
		#include <xsi_context.h>
		#include <xsi_pluginregistrar.h>
		#include <xsi_status.h>
		#include <xsi_x3dobject.h>
		#include <xsi_model.h>

		using namespace XSI;

		#ifdef unix
		extern "C"
		#endif
		CStatus XSILoadPlugin( XSI::PluginRegistrar& in_reg )
		{
			//This function is called by XSI to find out what commands or
			//other items have been defined inside this dll.
			in_reg.PutAuthor( L"Softimage" );
			in_reg.PutName( L"cppcommanddemo Plug-in" );
			in_reg.PutVersion( 1, 0 );

			in_reg.RegisterCommand( L"CommandHelloWorldCpp", L"CommandHelloWorldCpp" );
			in_reg.RegisterCommand( L"CommandSimpleCpp", L"CommandSimpleCpp" );
			in_reg.RegisterCommand( L"CommandSimpleObjectCpp", L"CommandSimpleObjectCpp" );

			return XSI::CStatus::OK;
		}

		#ifdef unix
		extern "C"
		#endif
		XSI::CStatus CommandHelloWorldCpp_Init( const XSI::CRef& in_context )
		{
			//This function is called to give you the opportunity to define the command.

			Context ctx(in_context);
			Command cmd(ctx.GetSource());
			cmd.EnableReturnValue( false ) ;

			// This command takes no arguments

			return CStatus::OK;
		}

		#ifdef unix
		extern "C"
		#endif
		XSI::CStatus CommandHelloWorldCpp_Execute( XSI::CRef& in_context )
		{
			Application app;
			app.LogMessage( L"Hello world" ) ;

			// Return a failure status if you want the
			// calling script to halt
			return CStatus::OK;
		}



		#ifdef unix
		extern "C"
		#endif
		XSI::CStatus CommandSimpleCpp_Init( const XSI::CRef& in_context )
		{
			Context ctx(in_context);
			Command cmd(ctx.GetSource());
			cmd.EnableReturnValue( true ) ;

			ArgumentArray args = cmd.GetArguments();

			// You must mention the arguments you want
			// The name is not important but must be unique
			args.Add( L"A" );
			args.Add( L"B" );

			return CStatus::OK;
		}

		#ifdef unix
		extern "C"
		#endif
		XSI::CStatus CommandSimpleCpp_Execute( XSI::CRef& in_context )
		{
			Application app;
			Context ctxt(in_context);

			// Access the arguments to the command
			CValueArray args = ctxt.GetAttribute( L"Arguments" );

			CValue argA = args[0] ;
			CValue argB = args[1] ;

			// Example of how you can
			// set the return value of the command
			CValue returnValue ;

			if ( argA.m_t == CValue::siString )
				returnValue = (CString)argA + (CString)argB ;
			else
				returnValue = (double)argA + (double)argB ;


			ctxt.PutAttribute( L"ReturnValue", returnValue );

			return CStatus::OK;
		}

		#ifdef unix
		extern "C"
		#endif
		XSI::CStatus CommandSimpleObjectCpp_Init( const XSI::CRef& in_context )
		{
			Context ctx(in_context);
			Command cmd(ctx.GetSource());

			cmd.EnableReturnValue( true ) ;

			ArgumentArray args = cmd.GetArguments();

			args.AddObjectArgument( L"obj" );

			return CStatus::OK;
		}

		#ifdef unix
		extern "C"
		#endif
		XSI::CStatus CommandSimpleObjectCpp_Execute( XSI::CRef& in_context )
		{
			Application app;

			Context ctxt(in_context);

			// Access the arguments to the command
			CValueArray args = ctxt.GetAttribute( L"Arguments" );
			CValue argObj = args[0] ;
			SIObject argSIObject = (CRef)argObj ;

			app.LogMessage( L"Name of the input object " + argSIObject.GetName() ) ;

			// Return a new object as the return value
			Model root = app.GetActiveSceneRoot();

			X3DObject returnObj;
			root.AddGeometry( L"Grid", L"MeshSurface", L"", returnObj );

			ctxt.PutAttribute( L"ReturnValue", returnObj.GetRef() );

			// Return a failure status if you want the
			// calling script to halt
			return CStatus::OK;
		}

		// To try out this example compile and put the resulting dll or
		// so file in your \Application\Plugins directory or update
		// the XSI_PLUGINS env variable.
		// Then run the following JScript code:

		// Demonstrate the custom commands that are defined in the plug-in
		DemoCommands() ;

		function DemoCommands()
		{
			// It is simple to execute a custom command, especially one
			// like this with no return value or arguments.

			// Will log "Hello World"
			CommandHelloWorldCpp() ;

			// Will log "15"
			logmessage( CommandSimpleCpp( 5, 10 ) );

			// Will log "concat"
			logmessage( CommandSimpleCpp( "con","cat" ) ) ;

			newscene( null, false ) ;
			var oSphere = ActiveSceneRoot.AddGeometry("Sphere", "NurbsSurface") ;

			//Will log:
			//INFO : "Name of the input object sphere"
			//INFO : "grid"
			logmessage( CommandSimpleObjectCpp( oSphere ) ) ;

			//XSI can also turn an string to an object:
			//INFO : "Name of the input object grid"
			//INFO : "grid1"
			logmessage( CommandSimpleObjectCpp( "grid" ) ) ;

		}
	\endcode
 */
//*****************************************************************************
class SICPPSDKDECL Command : public SIObject
{
public:
	/*! Default constructor. */
	Command();

	/*! Default destructor. */
	~Command();

	/*! Constructor.
	\param in_ref constant reference object.
	*/
	Command(const CRef& in_ref);

	/*! Copy constructor.
	\param in_obj constant class object.
	*/
	Command(const Command& in_obj);

	/*! Returns true if a given class type is compatible with this API class.
	\param in_ClassID class type.
	\return true if the class is compatible, false otherwise.
	*/
	bool IsA( siClassID in_ClassID) const;

	/*! Returns the type of the API class.
	\return The class type.
	*/
	siClassID GetClassID() const;

	/*! Creates an object from another object. The newly created object is set to
	empty if the input object is not compatible.
	\param in_obj constant class object.
	\return The new Command object.
	*/
	Command& operator=(const Command& in_obj);

	/*! Creates an object from a reference object. The newly created object is
	set to empty if the input reference object is not compatible.
	\param in_ref constant class object.
	\return The new Command object.
	*/
	Command& operator=(const CRef& in_ref);

	/*! Returns an array of Argument objects defined for this command.
	\since 4.0
	*/
	ArgumentArray GetArguments() ;

	/*! Returns the scripting name (\c ScriptingName) for the command.

	The scripting name is used for executing the command; for example, from a script or by calling Application::ExecuteCommand.
	Sometimes this string is different from the actual name of the command, which is often used as a label for menu or buttons
	and may have space characters in it.

	\sa SIObject::GetName
	\since 4.0
	*/
	CString GetScriptingName() const ;

	/*! Sets the scripting name (\c ScriptingName) for the command.  This name should not contain any spaces or start with a number.
	To avoid confusion it should be the same or very similar to the command's name.
	\sa PluginRegistrar::RegisterCommand, SIObject::GetName, Application::CreateCommand
	\since 4.0
	*/
	CStatus PutScriptingName( const CString & in_Str ) ;

	/*! Returns the handler name for a script-based command. The handler specifies the name of the function or subroutine that
	implements the command. In other words, the Handler is the name of the callback function that %XSI calls each time the command
	is invoked.

	For a command implemented with the C++ API as a self-installed plug-in this property is not necessary because the handler is
	determined based on the name of the command. For example the handler of \c HelloWorldCpp would be \c HelloWorldCpp_Execute().
	\since 4.0
	*/
	CString GetHandler() ;

	/*! Sets the handler name for a script-based command.  This is only necessary when defining a custom command that is implemented
	as a script.
	\since 4.0
	*/
	CStatus PutHandler( const CString & ) ;

	/*! Returns the language used for implementing this command's handler function.  The values can be either \c CPP (for C++ language)
	or one of the scripting language supported by %XSI: \c VBScript, \c JScript, \c PerlScript or \c Python.

	The caller of a command does not need to be concerned with this property because any command can be called from any supported
	scripting language or the C++ API.
	\since 4.0
	*/
	CString GetLanguage() ;

	/*! Sets the language used for implementing this command. It is not necessary to call this function for a custom command implemented
	as a self-installed plug-in.
	\since 4.0
	*/
	CStatus PutLanguage( const CString & ) ;

	/*! Returns the \c .dll or script file that implements the command.  For many built-in commands this property is not specified.
	\since 4.0
	*/
	CString GetFileName() ;

	/*! Sets the name of the file exposing the handler function. The full path should be specified.  It is not necessary to set this
	property for a custom command implemented inside a self-installed plug-in.
	\since 4.0
	*/
	CStatus PutFileName( const CString & ) ;

	/*! Returns the implementation of the command. This property only applies to script-based custom commands that are implemented by
	embedding the code directly in the command definition rather than using an external file.  For commands implemented with the C++ API
	this returns an empty string.
	\since 4.0
	*/
	CString GetCode() ;
	/*! Sets the implementation of a script-based custom command. This is a convenient way to implement small, simple script-based custom
	commands.  The code is stored as part of the Command definition.
	\sa Command::PutLanguage
	\since 4.0
	*/
	CStatus PutCode( const CString & ) ;

	/*! Returns true if the custom command returns a value.  If you call a command that does not return a value then %XSI always passes
	an empty CValue as the return value.
	\since 4.0
	*/
	bool IsReturnValueEnabled() ;

	/*! Many custom commands return values, for example a newly created object or a calculated number.  Other custom commands act like
	\a void functions in C++ and perform some operation but do not return any information.  This function allows you to signal whether the
	custom command can be expected to return a value or not. The default behavior is true.
	\since 4.0
	*/
	CStatus EnableReturnValue( bool ) ;

	/*! Returns a string containing a list of the categories that the command belongs to.  This information is similar to SIObject::Categories
	but this function returns a string delimited with the pipe (\c |) character rather than an array. Custom commands always belong to the
	\a Custom category. If the ::siCommandCategory argument was specified in the call to Application::CreateCommand then a string representing
	the specified category will be included in the returned string.
	\since 4.0
	*/
	CString GetCategory(  ) ;

	/*! Returns a string that describes the command.
	\since 4.0
	*/
	CString GetDescription() ;

	/*! Optionally sets a descriptive string for the command. The description is shown in the %XSI user interface (for example on the \a Customize
	\a Toolbar dialog).
	\since 4.0
	*/
	CStatus PutDescription( const CString & ) ;

	/*! Returns the tooltip string for the command.
	\since 4.0
	*/
	CString GetTooltip() ;

	/*! Optionally sets the tooltip.  This text will appear when the mouse hovers over a %command button on a toolbar.
	\since 4.0
	*/
	CStatus PutTooltip( const CString & ) ;

	/*! For advanced users.  Returns the GUID that %XSI uses internally to distinguish between different custom commands.  This can be used with
	the \xl CreateToolbarButton command.
	\since 4.0
	*/
	CString GetUID() ;

	/*! Returns false if the command has been disabled.
	\since 4.0
	*/
	bool IsEnabled() ;

	/*! Enables or disables a command.  This flag only affects the user interface; it does not block the command from being executed from
	a script. This property is often used in conjunction with the Menu API.  By default all custom commands are enabled.
	\since 4.0
	*/
	CStatus PutEnabled( bool ) ;

	/*! Distinguishes between custom commands and the commands that ship as part of the %XSI package (called either \a native or \a built-in commands).
	\since 4.0
	*/
	bool IsBuiltin() ;

	/*! Executes the underlying command.

	\note If the command expects arguments and none are specified then it is invoked with the default arguments.

	The recommended way to execute a command from the C++ API is to call Application::ExecuteCommand
	\since 4.0
	*/
	CStatus Execute( CValue& out_return ) ;

	/*! Returns the state of one of the various flags that affects command behavior. You can set the value of a flag with Command::SetFlag.
	\param in_whichflag Value from the ::siCommandCapabilities enum
	\sa Command::CannotBeUsedInBatch, Command::IsNotLogged, Command::SupportsKeyAssignment
	\since 4.0
	*/
	bool GetFlag( LONG in_whichflag )  ;

	/*! Sets the state of one of the various flags that affects command behavior.  You can test the value of these flags with Command::GetFlag.
	\note If the command already exists, you must call Command::Update to update the official definition of the command, otherwise the change
	is limited to the scope of that particular command object.
	\since 4.0
	*/
	CStatus SetFlag( LONG in_whichflag, bool in_newvalue )  ;
	/*! Sets the state of the ::siSupportsKeyAssignment flag (shortcut for \c Command::GetFlag(siSupportsKeyAssignment) ).
	\since 4.0
	*/
	bool    SupportsKeyAssignment()  ;
	/*! Sets the state of the ::siCannotBeUsedInBatch flag (shortcut for \c Command::GetFlag(siCannotBeUsedInBatch) ).
	\since 4.0
	*/
	bool    CannotBeUsedInBatch() ;
	/*! Sets the state of the ::siNoLogging flag (shortcut for \c Command::GetFlag(siNoLogging) ).
	\since 4.0
	*/
	bool    IsNotLogged()  ;

	/*! Commits changes to the current command to the command definition. Subsequent calls to the command need to match the new definition of
	the command. In other words, this allows you to change the behavior and signature of a command after it is added with Application::AddCommand.
	\tip Alternatively, you could remove the command completely (with Application::RemoveCommand) and redefine it from scratch.
	\warning Extra care must be taken when you update the definition of a command because it might break scripts that are relying on it.
	\note You cannot update the definition of built-in commands.
	\warning Do not call this for custom commands implemented in a self-installed plug-in because your changes will not be persisted the next time
		your plug-in is loaded.  Instead you can adjust the definition code in the \c Init callback and reload the plug-in using the \a %Plugin
		\a Manager dialog.
	\since 4.0
	*/
	CStatus Update()  ;

	private:
	Command * operator&() const;
	Command * operator&();
};

//*****************************************************************************
/*! \class CommandArray xsi_command.h
	\brief This object represents a collection of commands.

	The collection retrieved from Application::GetCommands contains the entire list of all the custom and
	built-in commands in the system. CommandArray::Filter can be used to reduce the list according to command
	categories.  You can access a command by name via CommandArray::GetItem.

	\warning This specialized array is returned by Application::GetCommands, it is not meant to be created
		and modified in user-defined functions. If you want to add and remove arbitrary items to a
		collection, you must use a CRefArray instead.

	\since 4.0
*/
class SICPPSDKDECL CommandArray : public CBase
{
	public:
	/*! Default constructor. */
	CommandArray();

	/*! Default destructor. */
	~CommandArray();

	/*! Constructor.
	\param in_ref constant reference object.
	*/
	CommandArray(const CRef& in_ref);

	/*! Copy constructor.
	\param in_obj constant class object.
	*/
	CommandArray(const CommandArray& in_obj);

	/*! Returns true if a given class type is compatible with this API class.
	\param in_ClassID class type.
	\return true if the class is compatible, false otherwise.
	*/
	bool IsA( siClassID in_ClassID) const;

	/*! Returns the type of the API class.
	\return The class type.
	*/
	siClassID GetClassID() const;

	/*! Creates an object from another object.
	\param in_obj constant class object.
	\return The new CommandArray object.
	*/
	CommandArray& operator=(const CommandArray& in_obj);

	/*! Creates an object from a reference object. The newly created object is
	set to empty if the input reference object is not compatible.
	\param in_ref constant class object.
	\return The new CommandArray object.
	*/
	CommandArray& operator=(const CRef& in_ref);

	/*! Returns a Command object at a specified index in the array.
	\param in_index The index of the Command.
	\since 4.0
	*/
	Command GetItem( LONG in_index ) const;

	/*! Returns a Command object based on its name.
	\param in_name The name of the command, which is the user-friendly version of the command name (SIObject::GetName), not the scripting name
	(Command::GetScriptingName) of the command.
	\sa Application::GetCommandByScriptingName
	\since 4.0
	*/
	Command GetItem( const CString& in_name ) const;

	/*! Accessor to elements at a given index.
	\param in_index Command object
	\since 4.0
	*/
	Command operator[]( LONG in_index );

	/*! Accessor to elements at a given index. This function can only be called by constant objects, the returned value is read-only.
	\param in_index constant Command object
	\since 4.0
	*/
	const Command operator[]( LONG in_index ) const;

	/*! Returns the number of Command objects in the array.
	\return The number of Command objects.
	\since 4.0
	*/
	LONG GetCount() const;

	/*! Returns a new instance of the command array containing only elements that match the specified categories. See SIObject::GetCategories.
	\tip To find all custom commands call CommandArray::Filter() with the \c Custom keyword.
	\since 4.0
	*/
	CommandArray Filter( CStringArray & in_keywords ) const ;

	/*! Convenience version of CommandArray::Filter() for the case when only a single keyword is being specified.
	\since 4.0
	*/
	CommandArray Filter( CString & in_keyword ) const ;
} ;

};

#endif // __XSICOMMAND_H__
