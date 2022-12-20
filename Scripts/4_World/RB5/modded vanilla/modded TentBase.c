modded class TentBase	
{
	
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
	
		Print("tent_base.CanReceiveAttachment");
		string attType = attachment.GetType();
		attType.ToLower();
		
		if(attType == "codelock")
		{
			return ScanUtils.CanPlaceCodeLock(GetKonfig().max_locks,GetKonfig().search_radius);
		}
		else{
			Print(attType);
			return super.CanReceiveAttachment(attachment, slotId );
		}
		
		
	
	}
  

}
