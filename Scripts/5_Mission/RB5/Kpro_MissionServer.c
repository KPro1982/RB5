modded class MissionServer extends MissionBase
{
	override void OnInit() {
		super.OnInit();
		
		Print("[Kpro_KonfigPro] OnInit");
		GetKonfig();
		GetRPCManager().AddRPC( "Kpro_KonfigPro", "RPCKonfig", this, SingeplayerExecutionType.Both );
	}
	
	void RPCKonfig( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy){
			GetRPCManager().SendRPC("Kpro_KonfigPro", "RPCKonfig", new Param1< Konfig >( GetKonfig() ), true, RequestedBy);
			Print("#########config requested");
		}
	}
}


