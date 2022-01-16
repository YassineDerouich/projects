from netmiko import ConnectHandler



Network_Device = { "host": "192.168.1.254",  #ip du routeur en SSH
                  "username": "cisco",
                  "password": "cisco",
                  "device_type": "cisco_ios",
                  "secret": "cisco",
}

Connect = ConnectHandler(**Network_Device)
Connect.enable()

interface = "interface s 3/"
ipaddress = "ip address 192.168.2."
commandas = [interface,ipaddress]
min=0
max=2
mask=" 255.255.255.0"


##############FONCTION AJOUTER IP SUR UN INTERVALLE###################
def ajouterip(interface,ipaddress,mask,commandas,min,max) :
    for i in range (min,max):  #nombre max d'interfaces
        commandas[0]=interface+str(i) #de interface 0 à max-1
        commandas[1]=ipaddress+str(i+1) #ip de .1 à  max
        for i in range (0,1):
            commandas[1]=commandas[1]+mask #ajoute masque à l'ip
            output = Connect.send_config_set(commandas)
            print(output)
            

            
#Exemple 1 : de l'interface s 3/0 à s 3/1 inclu
ajouterip("interface s 3/","ip address 192.168.2.", " 255.255.255.0",[interface,ipaddress],0,2)


#Exemple 2 : de l'interface g 3/0 à s g 3/3 inclu            
ajouterip("interface g 3/","ip address 192.168.4."," 255.0.0.0",[interface,ipaddress],0,4)




    


   


Connect.disconnect() #déconnexion de la session SSH


