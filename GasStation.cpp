/*
	此题打100颗星，务必10000%搞懂

	首先要搞清楚一个状况，从一个环的某个节点开始，无论它往顺时针还是逆时针走，其最后剩余的油
	都相等，因此我们只需要考虑顺时针的走法即可

	对于这个题我们可以一直往顺时针走，假如下一站的花费的油量不足以支撑走下去，我们就可以倒回去走
	此时剩余油量即使是负的也无所谓，因为只要最后走的剩余油量为正即可

	对于环状的题目，可以利用minVal与maxVal
	然后通过
	while (minVal < maxVal) 的结构来解决这个问题，其中minVal可以初始化为0，maxVal初始化为N-1
	minVal++代表往顺时针走，maxVal--代表往回走
	那么minVal与maxVal就可以代表起始走的位置.
	在本题中，若起始位置不符合，那么minVal++
 */
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int minVal = 0;
	int maxVal = gas.size() - 1;
	int remainGas = gas[minVal];
	while (minVal <= maxVal) {
		if (remainGas - cost[minVal] >= 0) {
			//注意最后走回去的时候不要多加了一次gas[MinVal]
			remainGas += ((minVal==maxVal ? 0 : gas[minVal+1])-cost[minVal]);
			minVal++;
		} else {
			remainGas += ((minVal==maxVal ? 0 : gas[maxVal]) - cost[maxVal]);
			maxVal--;
		}
	}
	return remainGas >= 0 ? (minVal % gas.size()) : -1;
}

//这是更简单的方法，trick是sum初始化为gas[maxVal]-cost[maxVal]
int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }