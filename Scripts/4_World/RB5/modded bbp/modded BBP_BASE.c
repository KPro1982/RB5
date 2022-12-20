modded class BBP_BASE	
{
	
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
	
		Print("fence.CanReceiveAttachment");
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
