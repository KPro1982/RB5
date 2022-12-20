class Konfig
{

	protected static string ConfigPATH = "$profile:\\RB5\\Config_settings.json";
	private static const string configRoot = "$profile:\\RB5\\";	
/////////////////////////////////////////////////////////////////////////////////////////////////////	
// Variables to save go here
//
	string ConfigVersion = "1";
	bool allowReport = true;
   	int search_radius;
    int max_containers;
    int max_locks; 
  	int enable_locktracking;
  	int enable_containertracking;
  	ref array<ref string> containerTypes = {};
  	ref array<ref string> containerKits = {};
	
	
// NonSerialed Variables that should not be saved go here
	[NonSerialized()]
	int ConfigInt = 1;

	
	
//////////////////////////////////////////////////////////////////////////////////////////////////
	
	void Load(){
		Print("[RB5] Loading Config");
		if (GetGame().IsServer()){
			
			if (FileExist(configRoot)==0) // Save Directory Does not Exist
	        {
	            Print("[RB5] '" + configRoot + "' does not exist, creating directory");
	            MakeDirectory(configRoot);
	        }
			
			if (FileExist(ConfigPATH)){ //If Config File exist load File
			    JsonFileLoader<Konfig>.JsonLoadFile(ConfigPATH, this);
				if (ConfigVersion != "1"){
					ConfigVersion = "1";
					Save();
				}
			}else{ //File does not exist create file

				Print(string.Format("^^^^^^Kits %1, Types %2", containerKits.Count(), containerKits.Count()));
				Save();
			}
		}
	}
	
	void Save(){
		JsonFileLoader<Konfig>.JsonSaveFile(ConfigPATH, this);
	}
	
	void Konfig()
	{
		containerTypes = new array<ref string>; 
  		containerKits = new array<ref string> ;
		max_locks = 8;
		search_radius = 60;
		max_containers = 8;
		enable_locktracking = 1;
		enable_containertracking = 1;
		containerTypes.Insert("Barrel_Green");
		containerTypes.Insert("Barrel_Blue");
		containerTypes.Insert("Barrel_Red");
		containerTypes.Insert("Barrel_Yellow");
		containerTypes.Insert("mmg_planter_box");
		containerTypes.Insert("mmg_greenhouse");
		containerTypes.Insert("mmg_craftable_tent");
		containerTypes.Insert("mmg_crate04_olive");
		containerTypes.Insert("mmg_crate04_black");
		containerTypes.Insert("mmg_crate04_blue");
		containerTypes.Insert("mmg_crate04_yellow");
		containerTypes.Insert("mmg_crate04_red");
		containerTypes.Insert("mmg_supply_crate_wood");
		containerTypes.Insert("mmg_supply_crate_grey");
		containerTypes.Insert("mmg_supply_crate_unfinished_wood");
		containerTypes.Insert("mmg_equipment_locker_green");
		containerTypes.Insert("mmg_equipment_locker_black");
		containerTypes.Insert("mmg_equipment_locker_grey");
		containerTypes.Insert("mmg_armored_cabinet_grey");
		containerTypes.Insert("mmg_armored_cabinet_green");
		containerTypes.Insert("mmg_armored_cabinet_rusty");
		containerTypes.Insert("mmg_locker02_blue");
		containerTypes.Insert("mmg_locker02_green");
		containerTypes.Insert("mmg_locker02_tan");
		containerTypes.Insert("mmg_old_safe_green");
		containerTypes.Insert("mmg_old_safe_grey");
		containerTypes.Insert("mmg_gun_rack_blue");
		containerTypes.Insert("mmg_gun_rack_green");
		containerTypes.Insert("mmg_gun_rack_tan");
		containerTypes.Insert("mmg_gun_rack_planks");
		containerTypes.Insert("mmg_craftable_gun_rack");
		containerTypes.Insert("mmg_lockable_gun_rack_grey");
		containerTypes.Insert("mmg_gun_wall_wooden");
		containerTypes.Insert("mmg_gun_wall_metal");
		containerTypes.Insert("mmg_army_box_green");
		containerTypes.Insert("mmg_army_box_medic");
		containerTypes.Insert("mmg_army_box_medic_grey");
		containerTypes.Insert("mmg_military_case_green");
		containerTypes.Insert("mmg_weapon_crate-wood");
		containerTypes.Insert("mmg_palette_storage");
		containerTypes.Insert("mmg_fridge_minsk_beige");
		containerTypes.Insert("mmg_fridge_minsk_blue");
		containerTypes.Insert("mmg_toolwagon_red");
		containerTypes.Insert("mmg_trashcan_yellow");
		containerTypes.Insert("mmg_trashcan_green");
		containerTypes.Insert("mmg_grenade_case_green");
		containerTypes.Insert("mmg_gear_stand");
		containerTypes.Insert("mediumtent");
		containerTypes.Insert("mediumtent_green");
		containerTypes.Insert("mediumtent_orange");
		containerTypes.Insert("largetent");
		containerTypes.Insert("cartent");
		containerTypes.Insert("partytent");
		containerTypes.Insert("partytent_blue");
		containerTypes.Insert("partytent_brown");
		containerTypes.Insert("partytent_lunapark");
		containerTypes.Insert("mmg_solo_locker_yellow");
		containerTypes.Insert("mmg_solo_locker_blue");
		containerTypes.Insert("mmg_solo_locker_red");
		containerTypes.Insert("mmg_solo_locker_grey");
		containerTypes.Insert("mmg_solo_locker_green");
		containerTypes.Insert("mmg_solo_locker_medic");
		containerTypes.Insert("mmg_solo_locker_purple");
		containerTypes.Insert("woodencrate");


		containerKits.Insert("mmg_planter_box_kit");
		containerKits.Insert("mmg_greenhouse_kit");
		containerKits.Insert("mmg_craftable_tent_kit");
		containerKits.Insert("mmg_equipment_locker_green_kit");
		containerKits.Insert("mmg_equipment_locker_black_kit");
		containerKits.Insert("mmg_equipment_locker_grey_kit");
		containerKits.Insert("mmg_locker02_blue_kit");
		containerKits.Insert("mmg_locker02_green_kit");
		containerKits.Insert("mmg_locker02_tan_kit");
		containerKits.Insert("mmg_gun_rack_kit_blue");
		containerKits.Insert("mmg_gun_rack_kit_green");
		containerKits.Insert("mmg_gun_rack_kit_tan");
		containerKits.Insert("mmg_craftable_gun_rack");
		containerKits.Insert("mmg_lockable_gun_rack_kit_grey");
		containerKits.Insert("mmg_gun_wall_kit_wooden");
		containerKits.Insert("mmg_gun_wall_kit_metal");
		containerKits.Insert("mmg_palette_storage");
		containerKits.Insert("mmg_fridge_kit_beige");
		containerKits.Insert("mmg_fridge_kit_blue");
		containerKits.Insert("mmg_solo_locker_yellow_kit");
		containerKits.Insert("mmg_solo_locker_blue_kit");
		containerKits.Insert("mmg_solo_locker_red_kit");
		containerKits.Insert("mmg_solo_locker_grey_kit");
		containerKits.Insert("mmg_solo_locker_green_kit");
		containerKits.Insert("mmg_solo_locker_medic_kit");
		containerKits.Insert("mmg_solo_locker_purple_kit");
		containerKits.Insert("woodencrate");
		Print("^^^^^^^^^^^Default Values Created");
	}
}
ref Konfig m_Konfig;

//Helper function to return Config
static ref Konfig GetKonfig()
{
	if (!m_Konfig)
	{
		m_Konfig = new Konfig;
			
		if ( GetGame().IsServer() ){
			m_Konfig.Load();
		}
	}
	return m_Konfig;
};
