template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insertBTree(bTreeNode<recType, bTreeOrder> *current,
											 const recType &insertItem,
											 recType &median,                              // defined outside
											 bTreeNode<recType, bTreeOrder>* &rightChild,  // defined outside
											 bool &isTaller)                               // defined outside
{
	if(current == NULL)
	{
		median = insertItem;
		rightChild = NULL;
		isTaller = true;
	}
	else
	{
		bool found;
		int location;
		searchNode(current, insertItem, found, location);
		if(found)
		{
			cout << "The insertItem is aready in the bTree." << endl;
		}
		else
		{
			insertBTree(current->children[location], insertItem, median, rightChild, isTaller);
			if(isTaller)
			{
				if(current->recCount < bTreeOrder - 2)
				{
					insertNode(current, median, rightChild, location);
					isTaller = false;
				}
				else
				{
					splitNode(current, median, rightChild, location, rightChild, median);
					isTaller = true;
				}
			}
		}
	}
}
