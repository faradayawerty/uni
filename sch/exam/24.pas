var s : string;
var p, i, n, e : integer;

begin
	readln(s);
	p := 1;

	for i := 1 to length(s) do
	begin 
		val(s[i], n, e);
		if e = 0 then
			p *= n;
	end;

	writeln(p);
end.
