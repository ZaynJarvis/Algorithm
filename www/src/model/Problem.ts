export class Problem {
  constructor(
    public id: string,
    public title: string = '',
    public description: string = '',
    public url: string = '',
    public time: number,
    public difficulty: number,
  ) {}

  parse() {
    return {
      id: this.id,
      title: this.title,
      description: this.description,
      url: this.url,
      time: this.time,
      difficulty: this.difficulty,
    };
  }
}
