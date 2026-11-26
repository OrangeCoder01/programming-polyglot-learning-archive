library ieee;
use ieee.std_logic_1164.all;

entity prio8 is
    port
    (
        w: in std_logic_vector(7 downto 0);
        y: out std_logic_vector(2 downto 0);
        valid: out std_logic
    );
end prio8;

architecture dataflow of prio8 is
    begin
        y <= "111" when w(7) = '1' else
             "110" when w(6) = '1' else
             "101" when w(5) = '1' else
             "100" when w(4) = '1' else
             "011" when w(3) = '1' else
             "010" when w(2) = '1' else
             "001" when w(1) = '1' else
             "000";

        valid <= '0' when w = "00000000" else '1';
end architecture dataflow;

