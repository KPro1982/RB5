modded class ActionDropItem
{
	
	override void OnExecuteServer( ActionData action_data )
	{
		Print("ActionDropItem()");
		if ( !GetGame().IsMultiplayer() )
		{

			PlayerBase p = PlayerBase.Cast(GetGame().GetPlayer());
			if(ScanUtils.IsBaseContainer(p.GetItemInHands()))
			{
				
				if(ScanUtils.CanPlaceContainer(GetKonfig().max_containers,GetKonfig().search_radius))
				{
					
					
					super.OnExecuteServer(action_data);
					return;
				}
				else{
			
					KMessage.Get().AddMsg(string.Format("You cannot drop this container as you have reached your limit for this base."));
				}
				
				
			} else {
			
					super.OnExecuteClient(action_data);
					return;
			
			}
		}
		
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		Print("ActionDropItem()");
		if (GetGame().IsMultiplayer() )
		{

			PlayerBase p = PlayerBase.Cast(GetGame().GetPlayer());
			if(ScanUtils.IsBaseContainer(p.GetItemInHands()))
			{
				
				if(ScanUtils.CanPlaceContainer(GetKonfig().max_containers,GetKonfig().search_radius))
				{
					
					
					super.OnExecuteClient(action_data);
					return;
				}
				else{
			
					KMessage.Get().AddMsg(string.Format("You cannot drop this container as you have reached your limit for this base."));
				}
				
				
			} else {
			
					super.OnExecuteClient(action_data);
					return;
			
			}
		}
	}
}
