class CfgPatches
{
	class RB5_Scripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"mmg_storage","BaseBuildingPlus","CodeLock","Notifications"};
	};
};
class CfgMods
{
	class DZ_RB5
	{
		name = "Kpro1982";
		dir = "RB5";
		credits = "Kpro1982";
		author = "Kpro1982";
		overview = "A new mod";
		creditsJson = "RB5/Scripts/Data/Credits.json";
		versionPath = "RB5/Scripts/Data/Version.hpp";
		type = "mod";
		inputs = "RB5\scripts\data\inputs.xml";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class imageSets{};
			class widgetStyles{};
			class engineScriptModule
			{
				value = "";
				files[] = {"scripts/1_core""RB5/scripts/common","RB5/scripts/1_core"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"scripts/3_Game""RB5/scripts/common","RB5/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"scripts/4_World""RB5/scripts/common","RB5/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"scripts/5_Mission""RB5/scripts/common","RB5/scripts/5_Mission"};
			};
		};
	};
};
