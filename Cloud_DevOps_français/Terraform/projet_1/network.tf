resource "aws_vpc" "main"      {

    cidr_block="10.0.0.0/16"
    tags = {
        Name="vpc-name"
    }
}

resource "aws_subnet" "public" {

    vpc_id= aws_vpc.main.id
    cidr_block = "10.0.1.0/24"

    tags= {
        Name="subnet-public"
    }
}

resource "aws_subnet" "private" {

    vpc_id= aws_vpc.main.id
    cidr_block = "10.0.2.0/24"

    tags = {
        Name="subnet-private"
    }
}

resource "aws_internet_gateway" "igw" {

    vpc_id = aws_vpc.main.id

}

resource "aws_eip" "ip-ngw" {
    vpc = true
}

resource "aws_nat_gateway" "ngw" {

    allocation_id = aws_eip.ip-ngw.id
    subnet_id = aws_subnet.public.id
}

resource "aws_route_table" "public" {
    vpc_id = aws_vpc.main.id

    route {
    cidr_block = "0.0.0.0/0"
    gateway_id = aws_internet_gateway.igw.id
}

    tags = {
        Name = "public-rtable"
    }
}

resource "aws_route_table" "private" {
    vpc_id = aws_vpc.main.id

    route {
    cidr_block = "0.0.0.0/0"
    nat_gateway_id = aws_nat_gateway.ngw.id
}

    tags = {
        Name = "private-rtable"
    }
}

resource "aws_route_table_association" "public" {

    subnet_id=aws_subnet.public.id
    route_table_id = aws_route_table.public.id
}

resource "aws_route_table_association" "private" {

    subnet_id=aws_subnet.private.id
    route_table_id = aws_route_table.private.id
}
