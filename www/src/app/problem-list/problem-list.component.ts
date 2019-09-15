import { Component, OnInit } from '@angular/core';
import { AngularFirestore } from '@angular/fire/firestore';
import { Problem } from '../../../src/model/Problem';
import { ProblemService } from '../problem.service';
@Component({
  selector: 'app-problem-list',
  templateUrl: './problem-list.component.html',
  styleUrls: ['./problem-list.component.scss'],
})
export class ProblemListComponent implements OnInit {
  problems: Problem[];
  selected = -1;
  constructor(private db: AngularFirestore, private problemService: ProblemService) {}

  ngOnInit() {
    const problemService = this.db.collection('problem').valueChanges();
    problemService.subscribe((p: Problem[]) => {
      p.sort((a, b) => b.time - a.time);
      this.problems = p;
    });
  }

  onClick(p: Problem, i: number) {
    this.problemService.setProblem(p);
    this.selected = i;
  }

  onCreate() {
    this.problemService.unsetProblem();
    this.selected = -1;
  }
}
