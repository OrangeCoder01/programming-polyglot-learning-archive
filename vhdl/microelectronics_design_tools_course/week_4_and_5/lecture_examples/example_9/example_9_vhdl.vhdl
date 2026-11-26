library ieee;
use ieee.std_logic_1164.all;

entity bin2gray3 is -- From the architecture, the entity can be realized.
    port
    (
        b: in std_logic_vector(2 downto 0);
        g: out std_logic_vector(2 downto 0)
    );
end entity bin2gray3;

architecture sel_arch of bin2gray3 is
    begin
        with (b) select
            g <= "000" when "000",
                 "001" when "001",
                 "011" when "010",
                 "010" when "011",
                 "110" when "100",
                 "111" when "101",
                 "101" when "110",
                 "100" when "111",
                 "000" when others;
end architecture sel_arch; 