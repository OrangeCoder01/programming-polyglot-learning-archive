library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity en_sat is
    port
    (
        x: in std_logic_vector(3 downto 0);
        y: out std_logic_vector(3 downto 0)
    );
end entity en_sat;

architecture ar_sat of en_sat is
    begin
        y <= x when (unsigned(x) < "1100") else "1100";
end architecture ar_sat;