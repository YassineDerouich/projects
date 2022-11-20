
resource "aws_instance" "linux" {

    ami = "ami-09d3b3274b6c5d4aa"
    instance_type = "t2.micro"
    subnet_id = aws_subnet.private.id

    iam_instance_profile = aws_iam_instance_profile.ssm-allow.name

    tags = {

        Name = var.tag_name
    }
}
