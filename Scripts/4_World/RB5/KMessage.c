class KMessage
{
	private static ref KMessage m_instance;
	ref array<string> m_messageQueue = {};

	void KMessage()
	{
		m_messageQueue = new array<string>;
		
	}
	
	static KMessage Get()
	{
	    if (!m_instance)
	    {
	        m_instance = new KMessage();
	    }
	    return m_instance;
    
	}
	
	void AddMsg(string msg)
	{
		if (!GetGame().IsDedicatedServer())
		{
			if(!IsSpam(msg))
			{
				NotificationSystem.SimpleNoticiation(msg, "Rational Bases", "RB5\\Scripts\\Data\\RBICON.edds");
			}
		}
		
	}
	
	
	bool IsSpam(string msg)
	{
		int qCount = m_messageQueue.Count();
		if(qCount > 0)
		{
			string lastmessage = m_messageQueue.Get(m_messageQueue.Count() - 1); 
		}
		
		if (qCount == 0 || msg != lastmessage)
		{
			m_messageQueue.Insert(msg);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RemoveFirst, 1.5 * 1000);
			return false;
		} else {
			return true;
		
		}
		
		
	}
	
	void RemoveFirst()
	{
		if(m_messageQueue.Count()> 0)
		{
			m_messageQueue.Remove(0);
			Print("Message Removed");
		}

	
	}

}
