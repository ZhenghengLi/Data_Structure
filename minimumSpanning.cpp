void msTreeType::minimumSpanning(int sVertex)
{
	int k;
	double minWeight;
	
	source = sVertex;
	bool visited[gSize];

	for (int j = 0; j < gSize; j++)
	{
		edgeWeights[j] = weights[source][j];   // smallest weight to the tree
		edges[j] = s;
		visited[j] = false;
	}

	edgeWeights[source] = 0;
	visited[source] = true;

	for (int i = 0; i < gSize - 1; i++)
	{
		minWeight = DBL_MAX;
		
		for (int j = 0; j < gSize; j++)
			if (!visited[j] && edgeWeights[j] <= minWeight)
			{
				k = j;
				minWeight = edgeWeights[j];
			}

		visited[k] = true;

		for (int j = 0; j < gSize; j++)
			if (!visited[j] && weights[k][j] < edgeWeights[j])
			{
				edgeWeights[j] = weights[k][j];
				edges[j] = k;
			}
	}
}

