// key(l) < key, key(r) >= key
void split (pitem t, int key, pitem & l, pitem & r) {
	if (!t) l = r = NULL;
	else if (key < t->key)
		split (t->l, key, l, t->l),  r = t;
	else
		split (t->r, key, t->r, r),  l = t;
}

void insert (pitem & t, pitem it) {
	if (!t)	t = it;
	else if (it->prior > t->prior)
		split (t, it->key, it->l, it->r),  t = it;
	else
		insert (it->key < t->key ? t->l : t->r, it);
}

void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r) t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
}
