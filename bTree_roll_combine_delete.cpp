template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::deleteNode(bTreeNode<recType, bTreeOrder>* node,
											int location
	)
{
	for(int i = location; i < node->recCount - 1; i++)
	{
		node->list[i] = node->list[i + 1];
		node->children[i + 1] = node->children[i + 2];
	}
	(node->recCount)--;
}


template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::combineNode(bTreeNode<recType, bTreeOrder>* parent,
									int parloc
	)
{
	bTreeNode<recType, bTreeOrder>* currentChild, sideChild;
	if(parloc == 0)
	{
		parloc++;
	}
	currentChild = parent->children[parloc];
	sideChild = parent->children[parloc - 1];
	sideChild->list[sideChild->recCount] = parent->list[parloc - 1];
	sideChild->children[sideChild->recCount + 1] = currentChild->children[0];
	for(int i = 0; i < currentChild->recCount; i++)
	{
		sideChild->list[sideChild->recCount + i + 1] = currentChild->list[i];
		sideChild->children[sideChild->recCount + i +2] = currentChild->children[i + 1];
	}
	sideChild->recCount = sideChild->recCount + currentChild->recCount + 1;
	delete currentChild;
	deleteNode(parent, parloc - 1);
}


template <class recType, int bTreeOrder>
bool bTree<recType, bTreeOrder>::rollNode(bTreeNode<recType, bTreeOrder>* parent,
										  int targetLoc
	)
{
	bool foundL = false, foundR = false;
	int locLonger;
	bTreeNode<recType, bTreeOrder>* currentChild, nextChild;
	if(targetLoc > 0)
	{
		locLonger = targetLoc - 1;
		while(locLonger >= 0)
		{
			if(parent->children[locLonger]->recCount > bTreeOrder / 2)
				break;
			else
				locLonger--;
		}
		if(locLonger >= 0)
		{
			foundL = true;
			for(int i = locLonger; i < targetLoc; i++)
			{
				currentChild = parent->children[i];
				nextChild = parent->children[i + 1];
				for(int j = nextChild->recCount; j > 0; j--)
				{
					nextChild->list[j] = nextChild->list[j - 1];
					nextChild->children[j + 1] = nextChild->children[j];
				}
				nextChild->children[1] = nextChild->children[0];
				nextChild->list[0] = parent->list[i];
				parent->list[i] = currentChild->list[currentChild->recCount - 1];
				nextChild->children[0] = currentChild->children[currentChild->recCount];
				(currentChild->recCount)--;
				(nextChild->recCount)++;
			}
		}
	}

	if(!foundL && targetLoc < parent->recCount)
	{
		locLonger = targetLoc + 1;
		whild(locLonger <= parent->recCount)
		{
			if(parent->children[locLonger]->recCount > bTreeOrder /2)
				break;
			else
				locLonger++;
		}
		if(locLonger <= parent->recCount)
		{
			foundR = true;
			for(int i = locLonger; i > targetLoc; i--)
			{
				currentChild = parent->children[i];
				nextChild = parent->children[i - 1];
				nextChild->list[nextChild->recCount] = parent->list[i - 1];
				nextChild->children[nextChild->recCount + 1] = currentChild->children[0];
				parent->list[i - 1] = currentChild->list[0];
				(nextChild->recCount)++;
				for(int j = 0; j < currentChild->recCount - 1; j++)
				{
					currentChild->list[j] = currentChild->list[j + 1];
					currentChild->children[j] = currentChild->children[j + 1];
				}
				currentChild->children[currentChild->recCount - 1] = currentChild->children[currentChild->recCount];
				(currentChild->recCount)--;
			}
		}
	}

	if(foundL || foundR)
		return true;
	else
		return false;

}
