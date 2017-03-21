#pragma once
#include <vector>

typedef smsHistory::history history;

class smsHistory {
public :
	class history {
	private :
		string from;
		string content;
	public :
		history(string _from, string _content):
			from(_from), content(_content) {}
		string getFrom();
		string getContent();
		void setFrom(string _from);
		void setContent(string _content);
	};
private :
	vector<history> histories;
public :
	smsHistory();
	
};