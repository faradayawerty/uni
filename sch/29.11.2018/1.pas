var i : integer;
var s : string;
var f : text;

begin
	assign(f, 'file1.txt');
	rewrite(f);

	for i := 1 to 5 do
	begin
		readln(s);
		writeln(f, s);
	end;

	close(f);
end.

