void weightedGraphType::shortestPath(int vertex)
{
	for (int j = 0; j < gSize; j++)
		smallestWeight[j] = weights[vertex][j];  
	                        // 0, nonnegative real number, DBL_MAX
	
	bool weightFound[gSize];
	for (int j = 0; j < gSize; j++)
		weightFound[j] = false;
	weightFound[vertex] = true;
	
	for (int j = 0; j < gSize; j++)
	{
		if (weights[vertex][j] == DBL_MAX)
			preVtx[j] = -1;                // previous vertex of j 
		else
			preVtx[j] = vertex;
	}
	
	for (int i = 0; i < gSize - 1; i++)
	{
		double minWeight = DBL_MAX;
		int v;

		for (int j = 0; j < gSize; j ++)
			if (!weightFound[j])
				if (smallestWeight[j] <= minWeight)
				{
					v = j;
					minWeight = smallestWeight[v];
				}

		weightFound[v] = true;

		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (minWeight + weights[v][j] < smallestWeight[j])
				{
					smallestWeight[j] = minWeight + weights[v][j];
					preVtx[j] = v;
				}
	}
}

void weightedGraphType::printPath(int start, int end)
{
	if (end < 0)
		cout << "There is no path from start to end." << endl;
	if (end == start)
		cout << start << " ";
	if (end != start)
	{
		printPath(start, preVtx[end]);
		cout << end << " ";
	}
}

