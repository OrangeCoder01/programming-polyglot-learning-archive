library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bcd7seg is
    port
    (
        bcd: in std_logic_vector(3 DOWNTO 0);
        seg: out std_logic_vector(6 downto 0);
    );
end entity bcd7seg;

architecture sel_arch of bcd7seg is
    begin
        with (bcd) select
            seg <= "1111110" when "0000",
            seg <= "0110000" when "0001",
            seg <= "1101101" when "0010",
            seg <= "1111001" when "0011",
            seg <= "0110011" when "0100",
            seg <= "1011011" when "0101",
            seg <= "1011111" when "0110",
            seg <= "1110000" when "0111",
            seg <= "1111111" when "1000",
            seg <= "1111011" when "1001",
                   "0000000" when others;
end architecture sel_arch;
