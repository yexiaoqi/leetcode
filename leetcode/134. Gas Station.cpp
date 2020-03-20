//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i + 1).You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//Note:
//The solution is guaranteed to be unique.
//��������������ǰ����gas������Ҫ����cost�������������Ż������Ĵ��ڡ����迪ʼ�������start = 0, 
//������������������ǰ��gasֵ����costֵ���Ϳ��Լ���ǰ������ʱ����һ��վ�㣬ʣ���gas���ϵ�ǰ��gas�ټ�ȥcost��
//���Ƿ����0��������0�������ǰ����������ĳһվ��ʱ�������ֵС��0�ˣ�
//��˵������㵽������м���κ�һ���㶼������Ϊ��㣬��������Ϊ��һ���㣬����������
//��������������ʱ����ǰ�������㼴Ϊ����
class Solution
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int start = 0, total = 0, tank = 0;
		for (int i = 0;i<gas.size();++i)
		{
			tank = tank + gas[i] - cost[i];
			if (tank<0)
			{
				start = i + 1;
				total += tank;
				tank = 0;
			}
		}
		return(total + tank<0 ? -1 : start);
	}
};

//��ϰ
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0, sum = 0, res = 0;
		for (int i = 0; i<gas.size(); ++i)
		{
			total += gas[i] - cost[i];
			sum += gas[i] - cost[i];
			if (sum<0)
			{
				res = i + 1;
				sum = 0;
			}
		}
		return total<0 ? -1 : res;
	}
};