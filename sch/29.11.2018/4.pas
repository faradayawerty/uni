var f : text;
var sum, x : integer;

begin
	assign(f, 'file4.txt');
	reset(f);

	sum := 0;

	while not eof(f) do
	begin 
		readln(f, x);
		sum += x;
	end;

	writeln(sum);
end.
