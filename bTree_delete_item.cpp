template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::delete_item(const recType& deleteItem)
{
	bTreeNode<recType, bTreeOrder>* posFound = NULL;
	int locFound;
	deleteFromBTree(NULL, 0, root, posFound, locFound, deleteItem);
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::deleteFromBTree(bTreeNode<recType, bTreeOrder>* parent,
												 int parloc,
												 bTreeNode<recType, bTreeOrder>* current,
												 bTreeNode<recType, bTreeOrder>* &pos,     // = NULL
												 int &loc,
												 const recType& deleteItem
	)
{
	if(pos == NULL && current == NULL)
		cout << "Cannot delete from empty tree." << endl;
	else if(pos == NULL)
	{
		bool found;
		int location;
		searchNode(current, deleteItem, found, location);
		if(!found && current->children[location] == NULL)
			cout << "The delete item is not in the tree." << endl;
		else if(!found)
		{
			deleteFromBTree(current, location, current->children[location], pos, loc, deleteItem   );
			if(current == root && root->recCount == 0)
			{
				root = current->children[0];
				delete current;
			}
			else if(current != root && current->recCount < bTreeOrder / 2)
			{
				if(!rollNode(parent, parloc))
					combineNode(parent, parloc);
			}
		}
		else if(found)
		{
			if(current->children[location] != NULL)
			{
				pos = current;
				loc = location;
				deleteFromBTree(pos, loc, pos->children[loc], pos, loc, deleteItem   );
				if(current == root && root->recCount == 0)
				{
					root = current->children[0];
					delete current;
				}
				else if(current != root && current->recCount < bTreeOrder / 2)
				{
					if(!rollNode(parent, parloc))
						combineNode(parent, parloc);
				}
				
			}
			else
			{
				deleteNode(current, location);
				if(current == root && root->recCount == 0)
				{
					delete root;
					root = NULL;
				}
				else if(current != root && current->recCount < bTreeOrder/2)
				{
					if(!rollNode(parent, parloc))
						combineNode(parent, parloc);
				}
			}
		}
	}
	else if(pos != NULL)
	{
		if(current->children[current->recCount] == NULL)
		{
			pos->list[loc] = current->list[current->recCount - 1];
			deleteNode(current, current->recCount - 1);
			if(current->recCount < bTreeOrder/2)
			{
				if(!rollNode(parent, parloc))
					combineNode(parent, parloc);
			}
		}
		else if(current->children[current->recCount] != NULL)
		{
			deleteFromBTree(current, current->recCount, current->children[current->recCount], pos, loc, deleteItem    );	
			if(current == root && root->recCount == 0)
			{
				root = current->children[0];
				delete current;
			}
			else if(current != root && current->recCount < bTreeOrder / 2)
			{
				if(!rollNode(parent, parloc))
					combineNode(parent, parloc);
			}
		}
	}
}
	
