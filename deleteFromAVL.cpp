
template<class elemT>
void deleteNode(const elemT &deleteItem)
{
	bool shorter = false;
	AVLNode<elemT>* position = NULL;
	deleteFromAVL(root, position, deleteItem, shorter);
}


template <class elemT>
void deleteFromAVL(AVLNode<elemT>* &root, AVLNode<elemT>* &pos, const elemT& deleteItem, bool& shorter)
{
	AVLNode<elemT> *temp;
	AVLNode<elemT> *temp2;
	if(pos == NULL && root == NULL)
		cout << "Cannot delete from the empty tree." << endl;
	else if(pos == NULL && root->llink == NULL && deleteItem < root->info ||
			pos == NULL && root->rlink == NULL && deleteItem > root->info )
		cout << "The delete item is not in the tree." << endl;
	else if(pos == NULL && root->info == deleteItem)
	{
		if(root->llink == NULL && root->rlink == NULL)
		{
			temp = root;
			root = NULL;
			delete temp;
			shorter = true;
		}
		else if(root->llink == NULL)
		{
			temp = root;
			root = temp->rlink;
			delete temp;
			shorter = true;
		}
		else if(root->rlink == NULL)
		{
			temp = root;
			root = temp->llink;
			delete temp;
			shorter = true;
		}
		else
		{
			pos = root;
			deleteFromAVL(root->llink, pos, deleteItem, shorter);
			if(shorter)
			{
				switch(root->bfactor)
				{
				case 0:
					root->bfactor = 1;
					shorter = false;
					break;
				case -1:
					root->bfactor = 0;
					shorter = true;
					break;
				case 1:
					temp = root->rlink;
					switch(temp->bfactor)
					{
					case 0:
						root->bfactor = 1;
						temp->bfactor = -1;
						rotateToLeft(root);
						shorter = false;
						break;
					case 1:
						root->bfactor = 0;
						temp->bfactor = 0;
						rotateToLeft(root);
						shorter = true;
						break;
					case -1:
						temp2 = temp->llink;
						switch(temp2->factor)
						{
						case 1:
							root->bfactor = -1;
							temp->bfactor = 0;
							break;
						case 0:
							root->bfactor = 0;
							temp->bfactor = 0;
							break;
						case -1:
							root->bfactor = 0;
							temp->bfactot = 1;
						}
						temp2->bfactor = 0;
						rotateToRight(temp);
						root->rlink = temp;
						rotateToLeft(root);
						shorter = true;
					}
				}
			}
		}
	}
	else if(pos != NULL)
	{
		if(root->rlink == NULL)
		{
			temp = root;
			pos->info = temp->info;
			root = temp->llink;
			delete temp;
			shorter = true;
		}
		else
		{
			deleteFromAVL(root->rlink, pos, deleteItem, shorter);
			if(shorter)
			{
				switch(root->bfactor)
				{
				case 0:
					root->bfactor = -1;
					shorter = false;
					break;
				case 1:
					root->bfactor = 0;
					shorter = true;
					break;
				case -1:
					temp = root->llink;
					switch(temp->bfactor)
					{
					case 0:
						root->bfactor = -1;
						temp->bfactor = 1;
						rotateToRight(root);
						shorter = false;
						break;
					case -1:
						root->bfactor = 0;
						temp->bfactor = 0;
						rotateToRight(root);
						shorter = true;
						break;
					case 1:
						temp2 = temp->rlink;
						switch(temp2->bfactor)
						{
						case 1:
							root->bfactor = 0;
							temp->bfactor = -1;
							break;
						case 0:
							root->bfactor = 0;
							temp->bfactor = 0;
							break;
						case -1:
							root->bfactor = 1;
							temp->bfactor = 0;
						}
						temp2->bfactor = 0;
						rotateToLeft(temp);
						root->llink = temp;
						rotateToRight(root);
						shorter = true;
					}
				}
			}
		}
	}
	else if(root->llink != NULL && deleteItem < root->info)
	{
		deleteFromAVL(root->llink, pos, deleteItem, shorter);
		if(shorter)
		{
			switch(root->bfactor)
			{
			case 0:
				root->bfactor = 1;
				shorter = false;
				break;
			case -1:
				root->bfactor = 0;
				shorter = true;
				break;
			case 1:
				temp = root->rlink;
				switch(temp->bfactor)
				{
				case 0:
					root->bfactor = 1;
					temp->bfactor = -1;
					rotateToLeft(root);
					shorter = false;
					break;
				case 1:
					root->bfactor = 0;
					temp->bfactor = 0;
					rotateToLeft(root);
					shorter = true;
					break;
				case -1:
					temp2 = temp->llink;
					switch(temp2->factor)
					{
					case 1:
						root->bfactor = -1;
						temp->bfactor = 0;
						break;
					case 0:
						root->bfactor = 0;
						temp->bfactor = 0;
						break;
					case -1:
						root->bfactor = 0;
						temp->bfactot = 1;
					}
					temp2->bfactor = 0;
					rotateToRight(temp);
					root->rlink = temp;
					rotateToLeft(root);
					shorter = true;
				}
			}
		}
	}
	else if(root->rlink != NULL && deleteItem > root->info)
	{
		deleteFromAVL(root->rlink, pos, deleteItem, shorter);
		if(shorter)
		{
			switch(root->bfactor)
			{
			case 0:
				root->bfactor = -1;
				shorter = false;
				break;
			case 1:
				root->bfactor = 0;
				shorter = true;
				break;
			case -1:
				temp = root->llink;
				switch(temp->bfactor)
				{
				case 0:
					root->bfactor = -1;
					temp->bfactor = 1;
					rotateToRight(root);
					shorter = false;
					break;
				case -1:
					root->bfactor = 0;
					temp->bfactor = 0;
					rotateToRight(root);
					shorter = true;
					break;
				case 1:
					temp2 = temp->rlink;
					switch(temp2->bfactor)
					{
					case 1:
						root->bfactor = 0;
						temp->bfactor = -1;
						break;
					case 0:
						root->bfactor = 0;
						temp->bfactor = 0;
						break;
					case -1:
						root->bfactor = 1;
						temp->bfactor = 0;
					}
					temp2->bfactor = 0;
					rotateToLeft(temp);
					root->llink = temp;
					rotateToRight(root);
					shorter = true;
				}
			}
		}
	}
}
