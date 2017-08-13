//Clone Graph
/*
	这个题解题的关键在于要考虑可能出现环的情况以及重复的节点

	那么我们可以多用一个map去存放保存的节点，一旦克隆了一个节点，就将该节点保存到map中
	这样重复的节点就直接返回该map的结果就可以了
 */
unordered_map<int, UndirectedGraphNode *> m;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL) return NULL;
	if (m.find(node->label) != m.end()) return m[node->label];
	UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
	m[node->label] = res;
	for (auto n = node->neighbors.begin(); n!= node->neighbors.end(); ++n) {
		res->neighbors.push_back(cloneGraph(*n));
	}
	return res;
}