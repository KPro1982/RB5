modded class ActionTogglePlaceObject
{

	override void Start( ActionData action_data )
	{
		Print("ActionTogglePlaceObject()");
		
		ItemBase item = action_data.m_MainItem;	
		Print(string.Format("Attempting to place/craft: [%1]", item.GetType()));
		
		int containerCount = 0;
		if(ScanUtils.IsBaseContainer(item) || ScanUtils.IsCraftableContainer(item))
		{
			Print(string.Format("Total containers = [%1]", containerCount ));
			if(!ScanUtils.CanPlaceContainer(GetKonfig().max_containers,GetKonfig().search_radius))
			{
						
				KMessage.Get().AddMsg(string.Format("You cannot place/deploy this container as you have reached your limit for this base."));
				return;
			} else {
				int containersRemaining = GetKonfig().max_containers - ScanUtils.CountContainers(GetKonfig().search_radius);
				KMessage.Get().AddMsg(string.Format("You will have [%1] containers left for this this base after you place this container.", containersRemaining - 1  ));

			}

			
		}
		
		super.Start(action_data);
		
		
		
		
		
		

						
	}
}
