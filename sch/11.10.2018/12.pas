var a : array[1..5] of integer;
var i : integer;


procedure write_sqr_and_sqrt(x : integer);
begin
	writeln(x*x,' ', sqrt(x));
end;


begin
	for i := 1 to 5 do
		readln(a[i]);
	
	for i := 1 to 5 do
		write_sqr_and_sqrt(a[i]);
end.


