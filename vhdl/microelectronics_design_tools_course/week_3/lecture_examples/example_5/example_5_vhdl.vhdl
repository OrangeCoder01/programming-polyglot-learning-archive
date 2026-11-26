library ieee;
use ieee.std_logic_1164.all;

entity enc42 is
    port
    (
        w: in std_logic_vector(3 downto 0);
        y: out std_logic_vector(1 downto 0);
        valid: out std_logic    
    );
end entity enc42;

architecture rtl of enc42 is
    begin
        y <= "00" when w = "0001" else
             "01" when w = "0010" else
             "10" when w = "0100" else
             "11" when w = "1000" else
             "00";
        
        valid <= '1' when ((w = "0001") or (w = "0010") or (w = "0100") or (w = "1000")) else '0';
end architecture rtl;