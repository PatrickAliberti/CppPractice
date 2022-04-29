double Queue::sell(int qty_to_rm) {
	double total_selling_price = 0;
	while (qty_to_rm > 0) {
		if (out->qty >= qty_to_rm) {
			total_selling_price += qty_to_rm * out->price;
			out->qty -= qty_to_rm;
			
			qty_to_rm = 0;
			
			if (out->qty <= 0) {
				int x;
				double y;
				pop(x, y);
			}
		}
		else {
			total_selling_price += out->qty * out->price;
			qty_to_rm -= out->qty;
			int x;
			double y;
			pop(x, y);
		}
	}
	
	return total_selling_price;
}
