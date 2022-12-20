class ScanUtils	
{
	
	
		
	static void SceneGetEntitiesInSphere(vector pos, float radius, out array<EntityAI> entList)
	{
	
		vector upperleft;
		vector lowerright;
		
		CalculateBoundingBox(pos, radius, lowerright, upperleft);
		DayZPlayerUtils.SceneGetEntitiesInBox(upperleft, lowerright, entList);
	
	}
	
	static void PhysicsGetEntitiesInSphere(vector pos, float radius, out array<EntityAI> entList)
	{
	
		vector upperleft;
		vector lowerright;
		
		CalculateBoundingBox(pos, radius, lowerright, upperleft);
		DayZPlayerUtils.PhysicsGetEntitiesInBox(upperleft, lowerright, entList);
	
	}
	static void CalculateBoundingBox(	vector 	pos, float radius, out vector upperleft, out vector lowerright)	
	{	
		vector vDisplacement = Vector(radius, radius, radius);
	
	
		upperleft = pos + vDisplacement;
		lowerright = pos - vDisplacement;
		
	
	}
	
	static int GetNearestFlagPole(vector pos, float radius, out vector flagPos)
	{
		
		int envFlags = 0;
		
		array<EntityAI> entities = new array<EntityAI>;
		
		SceneGetEntitiesInSphere(pos, radius, entities);
		
        for (int i = 0; i < entities.Count(); i++)
        {		
	
				if(entities.Get(i).GetDisplayName().Contains("Flag Pole"))
				{
					envFlags++;
					flagPos = entities.Get(i).GetPosition();
					Print(string.Format("Flag Pole Position = [%1]", flagPos.ToString()));
			 
				}
				
			
         }
		
		return envFlags;
	
	
	}
	
	
	
	
	
	
	
	
	static array<EntityAI> GetNearbyEntities(float protectedRadius)
	{
        array<EntityAI> entities = new array<EntityAI>;
		vector upperleft;
		vector lowerright;
		vector flagPos;
		
	
		
		int envFlags = GetNearestFlagPole(GetGame().GetPlayer().GetPosition(), protectedRadius, flagPos);
		
		if (envFlags == 0)
		{
			Print(string.Format("No flag pole within protected range! Using player position instead."));
			SceneGetEntitiesInSphere(GetGame().GetPlayer().GetPosition(), protectedRadius, entities);
		}
		else
		{
			SceneGetEntitiesInSphere(flagPos, protectedRadius, entities);
		}
	
		return entities;
                
	}
	
	static int CountCodeLocks(float protectedRadius)
	{
        array<EntityAI> entities = GetNearbyEntities(protectedRadius);
		
		
		int attLocks = 0;


        for (int i = 0; i < entities.Count(); i++)
        {		
				if(entities.Get(i).GetAttachmentByConfigTypeName("CodeLock") != null)
				{
					attLocks++;			 
				}
			
        }
		
		
		
			return attLocks;
                
	}
	static bool CanPlaceCodeLock(int maxLocks, float radius)
	{
		
		bool placeResult = true;
		
		
		int curLocks = CountCodeLocks(radius);
		
		if(curLocks < maxLocks)
		{		
			int remainingCodelocks = maxLocks - curLocks - 1;
			KMessage.Get().AddMsg(string.Format("You may use [%1] more code locks in this base.", remainingCodelocks));
			return true;
		}
		else{
			KMessage.Get().AddMsg(string.Format("You cannot place this code lock as you have reached your limit for this base."));	
			return false;	
		}
		
					
	}
	
	static bool CanPlaceContainer(int maxContainers, float radius)
	{
		bool placeResult = true;
				
		int curContainers = CountContainers(radius);
		Print(string.Format("Current containers = %1",curContainers)); 
		
		if(curContainers < maxContainers)
		{		
			int remainingCodelocks = maxContainers - curContainers;
			return true;
		}
		else{
			return false;	
		}
		
		
	
	}
	
	
	static int CountContainers(float protectedRadius)
	{
		array<EntityAI> entities = GetNearbyEntities(protectedRadius);
		int containerCount = 0;
		
		for (int i = 0; i < entities.Count(); i++)
        {		
			EntityAI envEntity = entities.Get(i);
			if(IsBaseContainer(envEntity) == true)
			{		
				if(!IsPackedTent(envEntity))
				{
					containerCount++;
					Print(string.Format("Found [%1]",envEntity.GetDisplayName()));
				}
			}			
        }	
		Print(string.Format("Total Containers found: [%1]",containerCount));
		
		return containerCount;					
	}
	
	
	
	static bool IsPackedTent(EntityAI item)
	{
		string eType = item.GetType();
		eType.ToLower();
		if(eType.Contains("tent"))
		{
					
			TentBase tent = TentBase.Cast(item);
			if(tent != null )
			{
				if(tent.GetState() == tent.PACKED)
				{
					Print(string.Format("Found Packed [%1] not counted against total.",item.GetDisplayName()));
					return true;
				}		
			}
			
		}
		return false;
	}
	


	static bool IsBaseContainer(EntityAI item)
	{ 
	/*

	*/
		string matchType = item.GetType();
		matchType.ToLower();
		return IsInConfig(matchType, GetKonfig().containerTypes);
		
	
	}
	
	static bool IsInConfig(string matchType, ref array<ref string> configList)
	{			
		
		int c = configList.Count();		
		
		for (int i = 0; i < configList.Count(); i++)
		{
			string cType = configList.Get(i);
			cType.ToLower();

			if(matchType == cType)
			{			
				return true;
			}	
		}
		return false;
	}
	
	static bool IsCraftableContainer(EntityAI item)	
	{
		string matchType = item.GetType();
		matchType.ToLower();
		return IsInConfig(matchType, GetKonfig().containerKits);
	
	}
	
	static string Report()
	{
		
		
		array<EntityAI> entities = GetNearbyEntities(GetKonfig().search_radius);
		int containerCount = 0;
		string reportOutput
		
		for (int i = 0; i < entities.Count(); i++)
        {		
			EntityAI envEntity = entities.Get(i);
			if(IsBaseContainer(envEntity) == true)
			{		
				if(!IsPackedTent(envEntity))
				{
					containerCount++;
					reportOutput += "- " + envEntity.GetDisplayName() + string.Format(", %1 m", GetDistance(envEntity)) + "\n";
				}
			}			
        }	
		
		reportOutput = string.Format("Found %1 containers.\n", containerCount) + reportOutput;
	
		return reportOutput;
	
	
	}
	
	static float GetDistance(EntityAI container)
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		vector playerLoc = player.GetPosition();
		vector containerLoc = container.GetPosition();
		float Dist = vector.Distance(playerLoc, containerLoc);
		
		return RoundFloatToSignificantDigits(Dist, 1);
	
	
	}
	
	static float RoundFloatToSignificantDigits(float numf, int sigdigit)
	{
		int powerf = Math.Pow(10,sigdigit);
		int temp = Math.Round(numf * powerf);
		return temp / powerf;	
	}
	
}
