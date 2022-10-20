class SegTree {
private:
	vector<ll> seg;
public:
	SegTree(ll n) {
		seg.resize(4*n+1,0);
	}
	void build(ll low,ll high,ll ind,ll arr[]) {
		if (low==high) {
			seg[ind]=arr[low];
			return;
		}
		ll mid=(low+high)>>1;
		build(low,mid,2*ind+1,arr);
		build(mid+1,high,2*ind+2,arr);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
	void update(ll low,ll high,ll ind,ll i,ll v) {
		if (low==high) {
			seg[ind]=v;
			return;
		}
		ll mid=(low+high)>>1;
		if (i<=mid) {
			update(low,mid,2*ind+1,i,v);
		}
		else {
			update(mid+1,high,2*ind+2,i,v);
		}
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
	ll query(ll low,ll high,ll ind,ll k) {
		if (low==high) {
			return low;
		}
		ll mid=(low+high)>>1;
		if (seg[2*ind+1]>=k) {
			return query(low,mid,2*ind+1,k);
		}
		else {
			return query(mid+1,high,2*ind+2,k-seg[2*ind+1]);
		}
		return -1;
	}
};
