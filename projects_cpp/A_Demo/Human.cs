using System;

class Human
{
    private int _id;
    public string Name { get; set; }
    public string Occupation { get; set; }
    public string Age { get; set; }

    public Human(int id, string name, string occupation, int age)
    {
        this._id = id;
        name = name;
        occupation = occupation;
        age = age;
    }
    
    public void Speak(string message)
    {
        Console.WriteLine(message);
    }
}



