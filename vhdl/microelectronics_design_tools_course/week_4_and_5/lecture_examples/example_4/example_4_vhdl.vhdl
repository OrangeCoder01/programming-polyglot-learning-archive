library ieee;
use ieee.std_logic_1164.all;

entity dec24 is
    port
    (
        en: in std_logic;
        w: in std_logic_vector(1 downto 0);
        y: out std_logic_vector(3 downto 0);
    );
end dec24;

architecture rtl of dec24 is
    begin
        y <= "0000"  when (en = '0') else
             "0001" when (w = "00") else
             "0010" when (w = "01") else
             "0100" when (w = "10") else
             "1000";
end architecture rtl;

