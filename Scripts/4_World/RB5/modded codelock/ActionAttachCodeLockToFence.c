modded class ActionAttachCodeLockToFence  {
    

    override void OnExecuteClient(ActionData action_data) {
       PlayerBase pBase = PlayerBase.Cast(GetGame().GetPlayer());
		bool result = ScanUtils.CanPlaceCodeLock(GetKonfig().max_locks,GetKonfig().search_radius);
		
		if(result) 
  			 super.OnExecuteClient(action_data);
    }

    override void OnExecuteServer(ActionData action_data) {
        PlayerBase pBase = PlayerBase.Cast(GetGame().GetPlayer());
		bool result = ScanUtils.CanPlaceCodeLock(GetKonfig().max_locks,GetKonfig().search_radius);
		
		if(result) 
  			 super.OnExecuteClient(action_data);
    }
}
