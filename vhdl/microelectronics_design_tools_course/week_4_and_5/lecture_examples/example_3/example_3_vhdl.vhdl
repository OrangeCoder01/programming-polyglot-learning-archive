library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity cmp4 is
    port
    (
        a, b: in std_logic_vector(3 downto 0);
        gt, eq, lt: out std_logic
    );
end entity cmp4;

architecture dataflow of cmp4 is
    begin
        gt <= '1' when unsigned(a) > unsigned(b) else '0';
        eq <= '1' when unsigned(a) = unsigned(b) else '0';
        lt <= '1' when unsigned(a) < unsigned(b) else '0';
end architecture dataflow;

