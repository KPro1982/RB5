modded class CraftWoodenCrate 
{	
	
  override bool CanDo(ItemBase ingredients[], PlayerBase player)
  {
		Print("CraftWoodenCrate.CanDo()");
		int result = ScanUtils.CanPlaceContainer(GetKonfig().max_containers,GetKonfig().search_radius);
		if(!result)
		{
			 KMessage.Get().AddMsg(string.Format("You cannot craft this container as you have reached your limit for this base."));
		}
		return result;		

  }
	
}
