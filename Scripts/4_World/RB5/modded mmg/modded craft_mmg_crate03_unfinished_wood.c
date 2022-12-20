modded class craft_mmg_crate03_unfinished_wood 
{	
	
  override bool CanDo(ItemBase ingredients[], PlayerBase player)
  {
		Print("craft_mmg_crate03_unfinished_wood.CanDo()");
		int result = ScanUtils.CanPlaceContainer(GetKonfig().max_containers,GetKonfig().search_radius);
		if(!result)
		{
			KMessage.Get().AddMsg(string.Format("You cannot craft this container as you have reached your limit for this base."));
		}
		return result;

  }
	
}
