var s1, s2 : string;
var n, i : integer;

begin
	readln(s1);
	readln(s2);

	n := 0;

	for i := 1 to length(s2) do
	begin
		if s2[i] = s1[1] then
			n += 1;
	end;

	writeln(n);
end.
