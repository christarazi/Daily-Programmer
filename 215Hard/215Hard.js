function getTruth(x)
{
	return Boolean(x);
}

var exprs = ["0", "0.0", "1", "1.0", "[]", "[1,2,3]", "{}", "\"0\"", "\"1\"", "\"\"", "'0'", "'1'", "''",
			"false", "true", "function f(){}", "Symbol()", "null", "undefined", "NaN"];
			
for (var item in exprs)
{
	console.log("truth of " + exprs[item] + ": " + getTruth(eval(exprs[item])));
}