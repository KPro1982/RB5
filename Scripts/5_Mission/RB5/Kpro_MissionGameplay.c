modded class MissionGameplay
{   
	
	override void OnUpdate(float timeslice)
	{        		
		super.OnUpdate(timeslice); 		
		if ( GetGame().GetInput().LocalPress("UARB") && GetGame().GetUIManager().GetMenu() == NULL ) 
		{				
			// KMessage.Get().AddMsg(string.Format("Maximum Code Locks Per Base = %1\nMaximum Containers Per Base = %2", GetKonfig().max_locks, GetKonfig().max_containers));
							
			if(GetKonfig().allowReport)
			{
				KMessage.Get().AddMsg(ScanUtils.Report());	
			} else {
			
				KMessage.Get().AddMsg(string.Format("Maximum Code Locks Per Base = %1\nMaximum Containers Per Base = %2", GetKonfig().max_locks, GetKonfig().max_containers));
			}
							
		}
			
	}
	
	override void OnMissionStart(){
		super.OnMissionStart();
		GetRPCManager().AddRPC( "Kpro_KonfigPro", "RPCKonfig", this, SingeplayerExecutionType.Both );
		Print("#########[Kpro_KonfigPro][Client] Requesting Config From Server");
		GetRPCManager().SendRPC("Kpro_KonfigPro", "RPCKonfig", new Param1< Konfig >( NULL ), true, NULL);
	}
	
	
	void RPCKonfig( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		Param1< Konfig > data;
		if ( !ctx.Read( data ) ) return;
		Print("########[Kpro_KonfigPro][Client] Received Config From Server");
		m_Konfig = data.param1;
	}
	

	
	
	
}
