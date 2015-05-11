void topologicalOrderType::dfTopOrder()
{
	linkedQueueType<int> queue;
	int topologicalOrder[gSize];
	int topIndex = gSize - 1;
	int succCount[gSize];

	for (int ind = 0; ind < gSize; ind++)
		succCount[ind] = graph[ind].length();

	for (int ind = 0; ind < gSize; ind++)
		if (succCount[ind] == 0)
			queue.addQueue(ind);

	while (!queue.isEmptyQueue())
	{
		int u = queue.front();
		queue.deleteQueue();
		topologicalOrder[topIndex--] = u;

		for(int ind = 0; int < gSize && succCount[ind] > 0; ind++)
			if (graph[ind].search(u))
			{
				succCount[ind]--;
				if (succCount[ind] == 0)
					queue.addQueue(ind);
			}
	}

	for (int ind = 0; ind < gSize; ind++)
		cout << topologicalOrder[ind] << " ";

	cout << endl;
}
	
