modded class PlayerBase	
{
		
	
	override bool CanDropEntity (notnull EntityAI item) 
  { 
		Print("CanDropEntity()");
	
		if(ScanUtils.IsBaseContainer(item))
		{		
			if(!ScanUtils.IsPackedTent(item))
			{
  				return ScanUtils.CanPlaceContainer(GetKonfig().max_containers,GetKonfig().search_radius);
			}
		}
		return super.CanDropEntity(item);
  }
  

}
