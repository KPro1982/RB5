modded class craft_mmg_gun_wall_kit_metal 
{	
	
  override bool CanDo(ItemBase ingredients[], PlayerBase player)
  {
		
		Print("craft_mmg_gun_wall_kit_metal.CanDo()");
		int result = ScanUtils.CanPlaceContainer(GetKonfig().max_containers,GetKonfig().search_radius);
		if(!result)
		{
			GetGame().ChatPlayer(string.Format("You cannot craft this container as you have reached your limit for this base."));
		}
		return result;		
		
  }
	
}
