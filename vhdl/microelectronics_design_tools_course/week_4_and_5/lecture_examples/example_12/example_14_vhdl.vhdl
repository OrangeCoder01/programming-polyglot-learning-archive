library ieee;
use ieee.std_logic_1164.all;

entity priority_encoder_4 is
    port
    (
        w: in std_logic_vector(3 downto 0);
        y: out std_logic_vector(3 downto 0);
        z: out std_logic
    );
end entity priority_encoder_4;

architecture rtl of priority_encoder_4 is
    begin
        process (w)
            begin
                y <= "00";
                z <= '0';

                if(w(3) = '1') then y <= "11"; z <= '1';
                elsif(w(2) = '1') then y <= "10"; z <= '1';
                elsif(w(1) = '1') then y <= "01"; z <= '1';
                elsif(w(0) = '1') then y <= "00"; z <= '1';
                end if;
        end process;
end architecture rtl;


    